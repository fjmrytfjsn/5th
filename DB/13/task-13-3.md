# task-13-3

```MySQL
create table sales(
    year int not null,
    sale int,
    primary key (year)
);

insert into sales values(2010, 50);
insert into sales values(2011, 51);
insert into sales values(2012, 52);
insert into sales values(2013, 52);
insert into sales values(2014, 51);

select S1.year, S1.sale from sales S1 where sale < (select sale from sales S2 where S2.year = S1.year-1);
```

```SHELL
year	sale
2014	51
```
