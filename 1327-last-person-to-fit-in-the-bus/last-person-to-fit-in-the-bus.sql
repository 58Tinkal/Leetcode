# Write your MySQL query statement below
select person_name
from ( select person_name, turn, sum(weight) over (order by turn) as cumulative_weight
      from Queue
) as subquery
where cumulative_weight <= 1000
order by turn desc
limit 1