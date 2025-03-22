# Write your MySQL query statement below
select p.product_id, coalesce(t.new_price, 10) as price
from products p
left join (
    select product_id, new_price 
    from products 
    where change_date = (select max(change_date) 
                         from products p2 
                         where p2.product_id = products.product_id 
                         and p2.change_date <= '2019-08-16')
) as t
on p.product_id = t.product_id
group by p.product_id;
