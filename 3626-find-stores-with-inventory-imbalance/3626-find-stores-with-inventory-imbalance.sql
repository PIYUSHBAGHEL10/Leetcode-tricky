# Write your MySQL query statement below
# Write your MySQL query statement below

with max_min_prices as (
select
store_id,
max(price) as max_price,
min(price) as min_price
from inventory
group by store_id
having count(distinct product_name ) >= 3
),

max_min_prod as (
select 
i.store_id,
i.product_name,
i.quantity,
i.price
from inventory i
join max_min_prices mp
on i.store_id = mp.store_id
and ( i.price = mp.max_price or i.price = mp.min_price)
)

select 
s.store_id,
s.store_name,
s.location,
me.product_name as most_exp_product,
ch.product_name as cheapest_product,
round(ch.quantity / me.quantity, 2) as imbalance_ratio
from max_min_prod me
join max_min_prod ch
on me.store_id = ch.store_id
and me.price > ch.price
and me.quantity < ch.quantity
join stores s
on s.store_id = me.store_id
order by imbalance_ratio desc, s.store_name asc;