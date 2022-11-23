# task6-4

## a

```MySQL
select * from order_t order by o_date, order_id;
```

## b

```MySQL
select order_id, sum(total) from order_t where category='D' group by order_id;
```

## c

```MySQL
select item_name, sum(total) from order_t group by item_name order by sum(total) desc;
```
