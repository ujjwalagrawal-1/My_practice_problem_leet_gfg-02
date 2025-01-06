# Write your MySQL query statement below
select unique_id , name
from Employees e LEFT JOIN EmployeeUNI p
on e.id = p.id;


-- SELECT unique_id , e.name
-- FROM Employees e
-- LEFT JOIN EmployeeUNI p
-- ON e.id = p.id;
