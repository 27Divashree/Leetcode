# Write your MySQL query statement below
Select p.product_name, sum(o.unit) AS unit
from products p JOIN orders o
USING (product_id)
WHERE YEAR(o.order_date)='2020' AND MONTH(o.order_date)='02'
GROUP BY p.product_id
HAVING SUM(o.unit)>=100;
