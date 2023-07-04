# Write your MySQL query statement below
Select * from users
where mail REGEXP '^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode[.]com$';
