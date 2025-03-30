# Write your MySQL query statement below
with rankSal as (
    select e.id, e.name as Employee, e.salary as Salary, e.departmentId, 
    d.name as Department,
    dense_rank() over (partition by e.departmentId order by e.salary desc) as sal_rank   
    from Employee as e
    join Department as d
    on e.departmentId = d.id
)
select Department, Employee, Salary
from rankSal
where sal_rank <= 3