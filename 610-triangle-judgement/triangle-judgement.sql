# Write your MySQL query statement below
select t.x, t.y, t.z, (case when (t.x+t.y>t.z and t.x+t.z>t.y and t.z+t.y>t.x) then 'Yes' else 'No' end) as triangle
from Triangle as t
