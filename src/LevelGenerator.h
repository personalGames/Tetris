/* 
 * File:   LevelGenerator.h
 * Author: dorian
 *
 * Created on 10 de diciembre de 2014, 13:31
 */

#ifndef LEVELGENERATOR_H
#define	LEVELGENERATOR_H

class LevelGenerator {
public:
    LevelGenerator();
    LevelGenerator(const LevelGenerator& orig);
    virtual ~LevelGenerator();
    
private:
    /**
     * Genera varias filas con el comando de building
     * según las filas o de forma aleatoria coloca un animal
     * el animal es un shape que no responde a colisiones, es decir, sus squares
     * no responden a colisiones. EL no responden a colisiones corresponde a que
     * el compare siempre devuelve false
     */

};

#endif	/* LEVELGENERATOR_H */

