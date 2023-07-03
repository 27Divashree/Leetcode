# Write your MySQL query statement below
SELECT b.employee_id as employee_id,b.name as name,count(*) as reports_count, round(avg(a.age)) as average_age
FROM Employees a JOIN Employees b ON a.reports_to = b.employee_id
GROUP BY 1
ORDER BY 1