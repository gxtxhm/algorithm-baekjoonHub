-- 코드를 작성해주세요

select ROUND(avg(coalesce(length,10)),2) as AVERAGE_LENGTH
from fish_info;
