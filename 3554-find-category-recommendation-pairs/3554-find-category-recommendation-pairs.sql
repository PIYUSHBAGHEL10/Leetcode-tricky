WITH user_categories AS (
Select DISTINCT pp.user_id, pin.category
From ProductPurchases pp 
INNER JOIN ProductInfo pin
ON pp.product_id = pin.product_id
), 
category_pairs AS (
Select a.category as category1, b.category as category2, a.user_id
From user_categories a 
INNER JOIN user_categories b 
ON a.user_id = b.user_id
AND a.category < b.category
)
Select p.category1, p.category2, count(distinct p.user_id) as customer_count
From category_pairs as p
Group by p.category1, p.category2
HAVING count(distinct p.user_id) >= 3
ORDER BY customer_count DESC, category1 ASC, category2 ASC;