/* Write your PL/SQL query statement below */
select name, bonus from Employee LEFT JOIN Bonus ON Employee.empId = Bonus.empId WHERE (bonus is null or bonus < 1000);