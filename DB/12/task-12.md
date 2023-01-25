# Task 12

## 12-1
sf1というDBを作成した。

```MySQL
sudo mysqlimport -u root -p --local --fields-terminated-by='|' sf1 ORDERS.tbl
sudo mysqlimport -u root -p --local --fields-terminated-by='|' sf1 LINEITEM.tbl
```
+------------+------------+-------+
| TABLE_NAME | TABLE_ROWS | allbm |
+------------+------------+-------+
| CUSTOMER   |          0 |     0 |
| LINEITEM   |     595482 |    90 |
| NATION     |          0 |     0 |
| ORDERS     |     148905 |    20 |
| PART       |          0 |     0 |
| PARTSUPP   |          0 |     0 |
| REGION     |          0 |     0 |
| SUPPLIER   |          0 |     0 |
+------------+------------+-------+
select count(*) from LINEITEM;
+----------+
| count(*) |
+----------+
|   600572 |
+----------+
1 row in set (0.04 sec)


mysql> select count(*) from ORDERS;
+----------+
| count(*) |
+----------+
|   150000 |
+----------+
1 row in set (0.06 sec)



## 12-2


mysql> select table_name, table_rows,
    -> floor((data_length+index_length)/1024/1024) AS allmb from
    -> information_schema.tables where table_schema=database();
+------------+------------+-------+
| TABLE_NAME | TABLE_ROWS | allmb |
+------------+------------+-------+
| CUSTOMER   |          0 |     0 |
| LINEITEM   |   11889460 |  1809 |
| NATION     |          0 |     0 |
| ORDERS     |    2897921 |   402 |
| PART       |          0 |     0 |
| PARTSUPP   |          0 |     0 |
| REGION     |          0 |     0 |
| SUPPLIER   |          0 |     0 |
+------------+------------+-------+
8 rows in set (0.00 sec)

mysql> select count(*) from LINEITEM;
+----------+
| count(*) |
+----------+
| 11997996 |
+----------+
1 row in set (4.41 sec)

mysql> select count(*) from ORDERS;
+----------+
| count(*) |
+----------+
|  3000000 |
+----------+
1 row in set (0.29 sec)


