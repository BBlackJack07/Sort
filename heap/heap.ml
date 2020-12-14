type 'a leftist =
    | Leaf
    | Node of 'a leftist * 'a * 'a leftist * int
;;

let singleton x = Node (Leaf, x, Leaf, 1);;

let rank = function
    | Leaf -> 0
    | Node (_,_,_,r) -> r
;;

let rec merge t1 t2 =
    match t1, t2 with
    | Leaf, t | t, Leaf -> t
    | Node (l, k1, r,_), Node (_, k2, _,_) ->
        if k1>k2 then merge t2 t1
        else
            let merged = merge r t2 in
            let rank_right = rank merged and rank_left = rank l in
            if rank_right > rank_left then
                Node (merged, k1, l, rank_left+1)
            else
                Node (l, k1, merged, rank_right+1)
;;

let insert x t = merge (singleton x) t;;

let get_min = function
    | Leaf -> failwith "empty"
    | Node (_,k,_,_) -> k
;;

let delete_min = function
    | Leaf -> failwith "empty"
    | Node (l,k,r,_) -> merge l r
;;
