use std::env;
use std::vec::Vec;
use std::str;

fn main() {
    println!("[TEST]");

    let args: Vec<String> = env::args().collect(); //Speichert Command Line Parameter

    //Argumente in Variablen Speichern:
    let mut mat_a;
    let mut mat_b;
    let mut mat_op;

    //prueft ob 3 Argumente mit gegeben wurden
    //Ansonsten: panic!(...), Also mit FehlerCode beenden
    if args.len() == 4{ 
        mat_a = &args[1];
        mat_op = &args[2];
        mat_b = &args[3];
    }else {
        panic!("Es muessen 3 Argumente benutzt werden!");
    }
    

    //Nach token trennen, test: nach Spaces:
    //for token in mat_a.split_whitespace(){
    //    println!("{}",token);
    //}

    //Nach ; splitten
    let mut vec_a: Vec<&str> = Vec::new();
    let mut vec_b: Vec<&str> = Vec::new();
    println!("Test: split mat_a und mat_b nach ';'");

    //Splitte mat_a
    let mut split_a = mat_a.split(";");

    for s in split_a{
        println!("{}",s);
        vec_a.push(s);
    }

    //Splitte mat_b
    let mut split_b = mat_b.split(';');

    for s in split_b{
        println!("{}",s);
        vec_b.push(s);
    }

    /*
    println!("Test: gebe vec_a aus:");
    for x in vec_a{
        println!("{}",x);
    }*/

     println!("Test: gebe vec_b aus:");
    for x in vec_b{
        println!("{}",x);
    }
    
    //let mut split_element_a = vec_a.split(",");
    let mut veci64_a: Vec<i64> = Vec::new();

    println!("Test: a nach ',' splitten ...");
    for line in vec_a{
        let mut split_element = line.split(",");
        println!("{:?}",split_element);
        let my_int:<i64> = split_element.parse::<i64>(); //das parsen funktioniert nicht
        veci64_a.push(my_int);
    }
    


    println!("Test: veci64_a ausgeben:");
    for x in veci64_a{
        println!("{}",x);
    }
    

    //println!("Matrix A:{:?} {:?} MatrixB:{:?}",mat_a, mat_op, mat_b);

    /*
    *To Do Liste:
    *
    * Nach " , " splitten + String nach <i64> konvertieren und in einem i64 Vektor speichern
    *Matrizen addieren bzw. multiplizieren
    *Ausgabe des Ergebnis
    */
}