# Write your MySQL query statement below

-- This can be say that it is the join of three tables of specific condition

select distinct l3.num as ConsecutiveNums
from 
Logs as l1,
Logs as l2,
Logs as l3
where(
    l1.id = l2.id - 1 and
    l2.id = l3.id - 1 and
    l1.num = l2.num and
    l2.num = l3.num
)