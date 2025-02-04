/* Write your PL/SQL query statement below */

SELECT S.student_id, S.student_name, su.subject_name, COUNT(E.student_id) AS attended_exams
FROM Students S CROSS JOIN Subjects su LEFT JOIN Examinations E 
ON E.student_id = S.student_id
AND su.subject_name = E.subject_name 
GROUP BY S.student_id, S.student_name, su.subject_name
ORDER BY S.student_id, S.student_name, su.subject_name
