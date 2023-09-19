# Write your MySQL query statement below
SELECT emp.name
FROM employee AS e
INNER JOIN employee AS emp
ON e.managerId=emp.id
GROUP BY e.managerId
HAVING COUNT(e.id) >= 5;