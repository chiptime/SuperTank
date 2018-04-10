function shoot (ob) {
    ob.lastshot=getTimer();
    game.bulletcounter++;
    if (game.bulletcounter>100) {
        game.bulletcounter=0;
    }
    var name = "bullet"+game.bulletcounter;
    game[name]= new game.Bullet;
    game[name].id=game.bulletcounter;
    game.bullets.push(game[name]);
    if (ob.dirx or ob.diry) {
        game[name].dirx= ob.dirx;
        game[name].diry= ob.diry;
    }
    game[name].xtile= ob.xtile;
    game[name].ytile= ob.ytile;
    game.clip.attachMovie("bullet", name, 10100+game.bulletcounter);
    game[name].clip=game.clip[name];
    game[name].x = (ob.x+game[name].dirx*ob.width);
    game[name].y = (ob.y+game[name].diry*ob.height);
    game.clip[name]._x = game[name].x;
    game.clip[name]._y = game[name].y;
}
