fn main(){
    let dst = cmake::build(".");

    println!("cargo:rustc-link-search=native={}", dst.display());

}