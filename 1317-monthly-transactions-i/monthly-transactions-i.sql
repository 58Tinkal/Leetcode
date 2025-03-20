# Write your MySQL query statement below
select DATE_FORMAT(t.trans_date, '%Y-%m') as month,
t.country as country,
count(*) as trans_count,
count(case when state = 'approved' then 1 else NULL end) as approved_count,
sum(t.amount) as trans_total_amount,
sum(case when state = 'approved' then t.amount else 0 end) as approved_total_amount
from Transactions as t
group by DATE_FORMAT(t.trans_date, '%Y-%m') , t.country