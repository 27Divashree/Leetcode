# Write your MySQL query statement below
Select * from cinema
where id%2!=0
and description NOT LIKE 'boring'
order by rating desc;