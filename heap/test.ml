open Heap

let scan_int ()= Scanf.scanf "%d\n" (fun x -> x);;

let read_tree () =
    let acc = ref Leaf in
    let rec loop () =
        let x = scan_int() in
        acc := insert x !acc; 
        loop () in
    try
        loop ()
    with
        End_of_file -> !acc
;;
 
let print_tree t =
    let rec loop acc =
        Printf.printf "%d " (get_min acc);
        loop (delete_min acc) in
    try 
        loop t 
    with
    | Failure _ -> print_newline() 
;;

let tree = (read_tree ()) in
print_tree tree;
print_newline();
