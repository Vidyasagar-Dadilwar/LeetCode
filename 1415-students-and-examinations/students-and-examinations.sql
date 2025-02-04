/* Write your PL/SQL query statement below */
select s.student_id, s.student_name, o.subject_name, count(e.subject_name) as attended_exams
from students s cross join subjects o left join examinations e
on s.student_id = e.student_id and o.subject_name = e.subject_name
group by s.student_id, s.student_name, o.subject_name 
order by s.student_id, s.student_name;