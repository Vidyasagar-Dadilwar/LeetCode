/* Write your PL/SQL query statement below */
select unique_id, name from EmployeeUNI a right outer join Employees b on a.id = b.id;

