-- 코드를 작성해주세요
select a.ID, coalesce(count(b.parent_id),0) as CHILD_COUNT
from ecoli_data a
left join ecoli_data b
on a.id = b.parent_id
group by a.id
order by a.id;