open Mergesort

let scan_int ()= Scanf.scanf "%d\n" (fun x -> x);;

let read_list () =
    let acc = ref [] in
    let rec loop () =
        let x = scan_int() in
        acc := x :: !acc; 
        loop () in
    try
        loop ()
    with
        End_of_file -> !acc
;;
 
let rec print_list = function
    | [] -> print_newline()
    | h::t -> Printf.printf "%d " h; print_list t
;;

let main () =
    let l = (read_list()) in
    print_list (mergeSort l)
in
main()
