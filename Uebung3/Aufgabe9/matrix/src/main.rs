static LOREM_IPSUM: &'static str =
"Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod
tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,
quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo
consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse
cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non
proident, sunt in culpa qui officia deserunt mollit anim id est laborum.
";

use std::error::Error;
use std::io::prelude::*;
use std::fs::File;
use std::path::Path;
use std::env;
use std::io;
use std::cmp::Ordering;

struct Matrix{
    rows: usize,
    cols: usize,
    data: Vec<i64>,
}

fn main() {
    println!("[TEST]");
    let args: Vec<String> = env::args().collect(); //Speichert Command Line Parameter
    println!("arguments:{:?}",args); //Test Ausgabe der Parameter

    let mut count = 0;

    for a in args.iter(){
        println!("argumente:{:?}",a);
        count = count +1;
    }
    println!("Anzahl Argumente:{}",count);


    //Argumente in Variablen Speichern:
    let mat_a = &args[1];
    let mat_op = &args[2];
    let mat_b = &args[3];
    let mod_out = &args[4];
    let mat_path = &args[5];

    //Nach token trennen, test: nach Spaces:
    for token in mat_a.split_whitespace(){
        println!("{}",token);
    }

    //Nach ; splitten
    let mut split = "ein kleines ; beispiel string".split(";");
    for s in split{
        println!("{}", s);
    }
    //in einem Vektor collecten:
    //ACHTUNG: funktioniert nicht
    //let vec: Vec<&str> = split.collect();

    //Test Ausgabe der Parameter:
    println!("Matrix A:{:?} {:?} MatrixB:{:?}",mat_a, mat_op, mat_b);

    //test slice Strings:
    println!("[TEST] Strings zerteilen ...");
    let slice = &"TEST_String"[..6];
    println!("{}",slice);
    
    //String literal erstellen:
    
    //"normal":
    let hello_world = "Hello, World";
    //literal:
    let hello_world2: &'static str = "Hello, World";



    let path = Path::new("lorem_ipsum.txt");
    let path = Path::new(mat_path);
    let display = path.display();

    // Oeffnet Datei im Write-Only Modus, returns `io::Result<File>`
    //pruefe ob Datei korrekt geoffnet wird, ansonsten beende Programm
    let mut file = match File::create(&path) { 
        Err(why) => panic!("couldn't create {}: {}",
                           display,
                           why.description()),
        Ok(file) => file,
    };

    // Schreibt den static String `LOREM_IPSUM` ind die Datei, returns `io::Result<()>`
    //Pruefe ob Datei richtig geoffnet wird
    match file.write_all(LOREM_IPSUM.as_bytes()) {
        Err(why) => {
            panic!("couldn't write to {}: {}", display,
                                               why.description())
        },
        Ok(_) => println!("successfully wrote to {}", display),
    }
}