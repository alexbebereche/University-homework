function addTokens(input, tokens){
    if(typeof input != 'string'){
        throw new Error('Invalid input'); // wrote invalid input as in TODO-RO, not TODO-EN...
    }
  
  
    if(input.length < 6){
        throw new Error('Input should have at least 6 characters');
    }


    if(tokens){
        tokens.forEach(element => {
            if(typeof (element.tokenName) != 'string'){  
                throw new Error('Invalid array format');
            }
        });
    }

    if(input.includes('...')){
        tokens.forEach(element =>{
            input = input.replace('...', '${' + element.tokenName + '}');  // {tokenName}
        });
    }

    return input;  // return input anyways...
    
}
 
const app = {
    addTokens: addTokens
}

module.exports = app;