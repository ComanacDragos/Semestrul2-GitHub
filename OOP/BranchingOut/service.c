#include "service.h"


ProductService* createService(ProductRepository* productRepository)
{
	ProductService* productService = (ProductService*)malloc(sizeof(ProductService));

	if (productService == NULL)
		return NULL;

	productService->productRepository = productRepository;
	productService->originalProductRepository = productRepository;

	productService->undoRedoListOfLists = createUndoRedoListOfLists();
	storeInUndoRedoListOfListsRepository(productService->undoRedoListOfLists, productRepository);

	return productService;
}

int storeProductService(ProductService* productService, char catalogueNumber[], char state[], char type[], char value[])
{
	Product newProduct = createProduct(atoi(catalogueNumber), state, type, atoi(value));

	int succes = storeProduct(productService->productRepository, newProduct);

	if (succes == 0)
		storeInUndoRedoListOfListsRepository(productService->undoRedoListOfLists, productService->productRepository);

	return succes;
}

int removeProductService(ProductService* productService, char catalogueNumber[])
{
	int succes = removeProduct(productService->productRepository, atoi(catalogueNumber));

	if (succes == 0)
		storeInUndoRedoListOfListsRepository(productService->undoRedoListOfLists, productService->productRepository);

	return succes;
}

Product getProductFromRepository(ProductService* productService, int index)
{
	return *getProduct(productService->productRepository, index);
}

void updateProductService(ProductService* productService, char catalogueNumber[], char state[], char type[], char value[])
{
	updateProduct(productService->productRepository, atoi(catalogueNumber), state, type, atoi(value));
	storeInUndoRedoListOfListsRepository(productService->undoRedoListOfLists, productService->productRepository);
}

int repositoryLengthService(ProductService* productService)
{
	return repositoryLength(productService->productRepository);
}

ProductRepository* listMaximumPotencyValueService(ProductService* productService, char maximumPotencyValue[])
{
	int maximumPotencyVal = atoi(maximumPotencyValue);

	ProductRepository* filteredProducts = createProductRepository();

	if (filteredProducts == NULL)
		return NULL;

	for (int i = 0; i < repositoryLength(productService->productRepository); i++)
	{
		Product currentProduct = getProductFromRepository(productService, i);
		if (getValue(&currentProduct) <= maximumPotencyVal)
			storeProduct(filteredProducts, currentProduct);
	}

	for(int i=0;i<repositoryLength(filteredProducts)-1;i++)
		for(int j=i+1;j<repositoryLength(filteredProducts);j++)
			if (strcmp(getState(getProduct(filteredProducts, i)), getState(getProduct(filteredProducts, j))) > 0)
			{
				Product auxiliaryInterchange = *getProduct(filteredProducts,i);
				*getProduct(filteredProducts, i) = *getProduct(filteredProducts, j);
				*getProduct(filteredProducts, j) = auxiliaryInterchange;
			}


	return filteredProducts;
}

void destroyService(ProductService* productService)
{
	destroyRepository(productService->originalProductRepository);
	destroyUndoRedoListOfLists(productService->undoRedoListOfLists);
	free(productService);
}

int undoService(ProductService* productService)
{
	if (productService->undoRedoListOfLists->currentRepositoryIndex == 0)
		return 1;

	productService->undoRedoListOfLists->currentRepositoryIndex -= 1;
	productService->productRepository = getCurrentProductRepositoryFromListOfLists(productService->undoRedoListOfLists);
	return 0;
}

int redoService(ProductService* productService)
{
	if (productService->undoRedoListOfLists->currentRepositoryIndex == productService->undoRedoListOfLists->lenght - 1)
		return 1;
	productService->undoRedoListOfLists->currentRepositoryIndex += 1;
	productService->productRepository = getCurrentProductRepositoryFromListOfLists(productService->undoRedoListOfLists);
	return 0;
}
