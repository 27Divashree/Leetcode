# Write your MySQL query statement below
(Select employee_id, department_id
from employee
where primary_flag = 'Y')
UNION
(
    Select employee_id, department_id
    From employee
    group by employee_id
    having count(department_id)=1
)