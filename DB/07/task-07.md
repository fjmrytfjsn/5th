# task7

## a

$$ 2 \times 6,000,000 / 1,000,000 / 0.5 = 24s$$

## b

$$ 2 \times 6,000,000 \times 0.0001 = 1200s$$

## c

lineitem表の最短アクセス時間は、$24s$。
orders表の最短アクセス時間は、
$$ 表スキャン：2 \times 1,500,000 / 1,000,000 / 0.5 = 6s $$
$$ 表索引アクセス；2 \times 1,500,000 \times 0.0001 = 300s$$
で、$6s$。

$$ 24 + (2 \times 6,000,000 \times 1) \times 6 = 72,000,024s$$

## d

$$ 6 + (2 \times 1,500,000 \times 1) \times 24 = 72,000,006s$$

## e

$$ 6 + (2 \times 1,500,000 \times 0.25) \times 24 = 18,000,006s$$

## f

```MySQL
select count(custkey) from customer where orders.totalprice>=100 and customer.address='兵庫' group by customer.custkey; 
```
