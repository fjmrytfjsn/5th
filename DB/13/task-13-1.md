# task-13-1

1. amazonで商品を注文する。
2. 注文リストに商品が追加される。
3. 出荷リストに商品が追加される。
4. 注文リストから商品が削除される。
5. 商品が発送される。
6. 発送済リストに商品が追加される。
7. 出荷リストから商品が削除される。

以下に、item1を購入した際の操作を示す。時系列は上から下である。

| リストへの操作           | 注文リスト(order) | 出荷リスト(ship) | 発送済リスト(shipped) |
| ----------------- | ------------ | ----------- | --------------- |
| R[order]          | null         | null        | null            |
| W[order+=item1]   | item1        | null        | null            |
| R[ship]           | item1        | null        | null            |
| W[ship+=item1]    | item1        | item1       | null            |
| R[order]          | item1        | item1       | null            |
| W[order-=item1]   | null         | item1       | null            |
| R[shipped]        | null         | item1       | null            |
| W[shipped+=item1] | null         | item1       | item1           |
| R[ship]           | null         | item1       | item1           |
| W[ship-=item1]    | null         | null        | item1                |
