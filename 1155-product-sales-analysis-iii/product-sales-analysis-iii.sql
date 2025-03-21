# Write your MySQL query statement below
select s.product_id, s.year as first_year, sales.quantity as quantity, sales.price as price
from (
   select product_id, min(year) as year from Sales group by product_id
) as s
left join sales 
on s.product_id = sales.product_id and s.year = sales.year
