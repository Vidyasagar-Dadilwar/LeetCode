/* Write your PL/SQL query statement below */
select a.machine_id, round(avg(b.timestamp - a.timestamp), 3) as processing_time
from Activity a, Activity b where a.machine_id = b.machine_id
    and a.process_id = b.process_id and a.timestamp < b.timestamp
    group by a.machine_id order by machine_id;