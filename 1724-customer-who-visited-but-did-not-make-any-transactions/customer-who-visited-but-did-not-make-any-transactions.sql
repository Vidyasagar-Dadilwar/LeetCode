/* Write your PL/SQL query statement below */
select v.customer_id, count(v.visit_id) as COUNT_NO_TRANS from Visits V
    left outer join 
    Transactions t on v.visit_id = t.visit_id
    where t.visit_id is NULL GROUP BY v.customer_id;