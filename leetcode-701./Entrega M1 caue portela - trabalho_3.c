// Caue Portela - M1 - trabalho M3 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */  
/*  
//nao preciso fazer o dfs com recursivdade 


1. Criar o novo nó com o malloc. 
2. novo nó receber o target.
3. verificar se o ponteiro da arvore não está vazio.  
4. usar ponteiro temporario para ficar com o root (para não perder ele) 
5. fazer verificação para colocar o novo nó no lugar certo 
*/
 //inserção de um novo nó dentro da arvore 


struct TreeNode* insertIntoBST(struct TreeNode* root, int val) { 

    struct TreeNode* novo_no = (struct TreeNode*)malloc(sizeof(struct TreeNode)); //malloc para criar o novo nó para inserir com aloc dinamica

    novo_no->val = val; // novo nó 
    
    novo_no->right = NULL; //NULL inicial

    novo_no->left = NULL; //NULL inicial 
    
    struct TreeNode* temp = root; // temporario
    struct TreeNode* prev = root; // anteriior

    if(root == NULL) return novo_no; // se não tiver ponteiro inicial, só vai retornar o valor (validação para o caso padrão)

    while (temp != NULL) { // enquanto a temp não estivel null (root atual)
        prev = temp; // prev vai receber o valor da temp(root) e vai comparar
        if (val < temp->val) {// se o valor for < que o root-> val, vai para a esquerda
            temp = temp->left;  // temp agora vai ir p esquerda
        }
        else {
            temp = temp->right; // se não vai para a direita
     } 
      }

    if (val < prev->val) prev->left = novo_no; // mesma validação só que para o anterior, recebendo o novo nó
        
    else {
        prev->right = novo_no; //mesma coisa só que para a direita
    }
    return root; // retorna o ponteiro inicial da estrutura da arvore
}
