function removeOrderItem(orderInfo, position){
    if(Array.isArray(orderInfo.items)){
        console.log("it is an array");
    }
    else{
        
    throw new Error("Items should be an array");
    }


    for(let i = 0; i < orderInfo.items.length; i++){
        if(orderInfo.items[i].price == undefined || orderInfo.items[i].quantity == undefined){
            throw new Error("Malformed item");
        }
    
    }
    
    if(position < 0 || position >= orderInfo.items.length){
        throw new Error("Invalid position");
    }


    orderInfo.total -= orderInfo.items[position].price * orderInfo.items[position].quantity;

    orderInfo.items.splice(position, 1);


    return orderInfo;

}


const app = {
    removeOrderItem
};

module.exports = app;
