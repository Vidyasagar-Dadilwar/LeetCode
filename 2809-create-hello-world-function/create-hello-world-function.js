const fs=require('fs')
const createHelloWorld = function() {
    return()=>"Hello World";
};
process.on('exit',()=>{
    fs.writeFileSync('display_runtime.txt',"0");
})