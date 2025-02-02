/* Write your PL/SQL query statement below */
select tweet_id from Tweets Where LENGTH(TRIM(content)) > 15;