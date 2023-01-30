# task-12-5

```MySQL
create table order_t(
    o_id char(3) not null,
    c_id char(3) not null,
    item_id char(3) not null,
    item_name varchar(20),
    unit int,
    total int, primary key (o_id)
);

create table cust(
    c_id char(3) not null,
    c_name varchar(20),
    city varchar(20), primary key (c_id)
);

insert into order_t values('001', 'C01', 'A01', 'オフィス用紙A4', 1, 2000);
insert into order_t values('002', 'C01', 'A02', 'オフィス用紙A3', 2, 8000);
insert into order_t values('003', 'C03', 'A01', 'オフィス用紙A4', 3, 6000);
insert into cust values('C01', '会社A', '神戸');
insert into cust values('C02', '会社B', '明石');
insert into cust values('C03', '会社C', '加古川');

select o_id, item_name, unit, total from order_t where '神戸' in (select city from cust where c_id=order_t.c_id);
```

```SHELL
o_id	item_name      unit     total
001	    オフィス用紙A4  1        2000
002	    オフィス用紙A3  2        8000
```