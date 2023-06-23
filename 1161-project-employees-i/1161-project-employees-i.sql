# Write your MySQL query statement below
Select p.project_id, round(sum(e.experience_years)/count(p.employee_id),2) as average_years
from project p, employee e
where e.employee_id = p.employee_id
group by project_id;