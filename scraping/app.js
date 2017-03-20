let cheerio = require("cheerio"),
    fs = require("fs"),
    request = require("request");

let tampung="";
let start=1;
let hal=0;

function scrap(url){
    request(url, function(error, response, html){
        //console.log(error);
        //console.log(response);
        //console.log(html);
        hal++;
        let $ = cheerio.load(html);
        if(!error){
            let tampil = $('.titleField') ;
            for (let awal=0; awal<tampil.length; awal++) {  
                if(awal == 0 && hal==1){
                    tampung = tampung + start+". "+($(tampil[awal]).text());
                }
                else{
                    tampung = tampung +"\n" + start + ". " + ($(tampil[awal]).text());
                }
                start++;
            }
        }
        
        fs.writeFile("simpan.txt", tampung, function(err){
               if(err){
                   return console.log(err);
               } 
                //console.log("File saved");
            });
        
    if(hal == 331){
        console.log("Scrapping End");
        console.log("File Tersimpan");
    }
    else{
        let next = $('.next_link')[0].attribs.href;
        scrap('http://library.itats.ac.id'+next);
    }
    });
}

let urls='http://library.itats.ac.id/index.php?search=search&keywords=&page=1';
scrap(urls);
