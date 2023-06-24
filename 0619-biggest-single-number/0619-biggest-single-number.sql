# Write your MySQL query statement below
Select max(num) as num from (Select count(num) as count_num,num from mynumbers group by num) as subquery where subquery.count_num=1;
