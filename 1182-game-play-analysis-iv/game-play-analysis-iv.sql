# Write your MySQL query statement below
select round(count(*)/(select count(distinct player_id) from activity) ,2) as fraction
from activity as a
where (player_id, event_date) in (
    select player_id, date_add(min(event_date),interval 1 day)
    from activity 
    group by player_id
)