# Write your MySQL query statement below
Select u.product_id, ROUND(SUM(p.price*u.units)/SUM(u.units),2) AS average_price
FROM UnitsSold u
JOIN prices p 
ON 1=1
AND p.product_id = u.product_id
AND u.purchase_date BETWEEN p.start_date AND p.end_date
group by product_id;