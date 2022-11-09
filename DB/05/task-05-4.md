# 課題5-4

## a

```MySQL
c_id    sum(total)
C01     10000
C03     6000
```

## b

```MySQL
select c_id,sum(total) from order_t where unit>=2 group by c_id;
```

## c

```MySQL
select c_id from order_t group by c_id having sum(total)>=7000;
```
