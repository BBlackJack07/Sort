let split lst =
  let orig_len = List.length lst in
  let rec split len acc = function
    | [] -> ([], [])
    | h::t as l -> if len > orig_len/2 then split (pred len) (h::acc) t
    else (List.rev acc, l)
  in
  split orig_len [] lst
;;

let merge one two =
  let rec merge one two acc =
    match one, two with
    | [],[] -> List.rev acc
    | [], l | l, [] -> finish l acc 
    | h1::t1, h2::t2 -> if h1<=h2 then merge t1 two (h1::acc)
    else merge one t2 (h2::acc)
  and finish acc = function
  | [] -> acc
  | h::t -> finish (h::acc) t
  in merge one two []
;;

let rec mergeSort l = 
  match l with
  | [] -> []
  | x::[] -> x::[]
  | h::t -> let one,two = split l in merge (mergeSort one) (mergeSort two)
;;