function buildArray(target: number[], n: number): string[] {
    let res : string[] = [];
    let stack : number[] = [];
    let j=0;
    for(let i=1; i<=n ;i++){
        stack.push(i);
        res.push("Push");
        if(i===target[j]){
            if(j===target.length-1) break;
            j++;
        }
        else{
            stack.pop();
            res.push("Pop");
        }
        
    }
    return res;

};