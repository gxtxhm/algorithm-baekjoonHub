-- 코드를 입력하세요
SELECT history_id,car_id,
date_format(start_date,'%Y-%m-%d') as START_DATE,
date_format(end_date,'%Y-%m-%d') as END_DATE, 
    case 
        when datediff(end_date,start_date) >= 29 then '장기 대여' else '단기 대여'
    end as RENT_TYPE
from car_rental_company_rental_history
where start_date between '2022-09-01' and '2022-09-30'
order by history_id desc;