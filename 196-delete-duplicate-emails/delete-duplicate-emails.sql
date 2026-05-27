# Write your MySQL query statement below
delete from Person as p1
where p1.id not in (
    select id from (
        select min(id) as id
        from Person
        group by email
    ) temp
)