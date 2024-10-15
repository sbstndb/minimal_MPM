# Compilateurs
NVCC = nvcc
GPP = g++

# Répertoires
SRCDIR = src
OBJDIR = obj

# Fichiers sources
CUFILES = $(wildcard $(SRCDIR)/*.cu)
CPPFILES = $(wildcard $(SRCDIR)/*.cpp)
CUOBJS = $(patsubst $(SRCDIR)/%.cu, $(OBJDIR)/%.cu.o, $(CUFILES))
CPPOBJS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.cpp.o, $(CPPFILES))
TARGET = main

# Options de compilation
NVCCFLAGS = -ccbin=$(GPP) -Xcompiler -fPIC
GPPFLAGS = -fPIC

# Chemins des bibliothèques CUDA (à ajuster si nécessaire)
CUDA_LIB_DIR = /usr/local/cuda/lib64
CUDA_INC_DIR = /usr/local/cuda/include

# Règles
all: $(OBJDIR) $(TARGET)

# Création du répertoire des objets
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Compilation des fichiers .cu en objets
$(OBJDIR)/%.cu.o: $(SRCDIR)/%.cu
	$(NVCC) $(NVCCFLAGS) -c $< -o $@

# Compilation des fichiers .cpp en objets
$(OBJDIR)/%.cpp.o: $(SRCDIR)/%.cpp
	$(GPP) $(GPPFLAGS) -c $< -o $@

# Édition de liens
$(TARGET): $(CUOBJS) $(CPPOBJS)
	$(GPP) $(GPPFLAGS) -o $@ $(CUOBJS) $(CPPOBJS) -L$(CUDA_LIB_DIR) -lcudart

clean:
	rm -f $(TARGET) $(OBJDIR)/*.o

