# task-11-4

```MySQL
select S1.year, S1.sale from sales S1 where sale < (select sale from sales S2 where S2.year=S1.year-1);
```
