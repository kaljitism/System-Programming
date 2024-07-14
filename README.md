# 1. Vim -

**Vi** i**m**proved

## **State Transitions** -

i = insert
I = insert at start of the line
a = append
A = append at the end of the line
c = change
C = change at the end of the line
o = insert a line below
O = insert a line above
u = undo change
h = move one character left
l = move one character right
j = move one line below
k = move one line above
Ctrl+r = redo
. = repeat last operation
Ctrl+[  = Esc/ normal mode
v = visual
Shift+V = line mode
Ctrl+V = column mode
dd = delete
y = yank
ZZ = quit after saving
ZQ = quit without saving
:       = command mode
:w = write
:wq = write and quit
:q = quit
:q!     = quit without saving

# 2. VCS & git -

> **V**ersion **C**ontrol **S**ystem/ Source Control, is the practice of
> tracking and managing changes to software code.
> - Altassian

> git - A free and open-source distributed version control system that was
> specifically designed to handle the development of the Linux kernel.
> - Sir Linus Torvalds, 2005

- **core git** is the fundamental data structures and utilities of Git. It
  only exposes very limited source code management tools. Cute name for it
  is **plumbing**.
- **Porcelain** is the cute name for programs and program suites depending
  upon Core git, presenting high level access to it. It exposes more of an
  SCM interface than plumbing.
- SCM - Source Code Management.
- **file system** - Git is user space file system i.e. the infrastructure to
  hold files and directories
- **gitfile**: a plain file `.git` at the root of the working tree that
  points at the directory that is the real repository.

## Reference

- **ref** is a name that begins with `refs/`(eg, `refs/heads/master`) that
  points to an object name or another ref(latter is called **symref**). Refs are
  stored in the repository.
- Ref Namespace is hierarchical, different sub-hierarchies are used for
  different purposes.
- `refs/heads` hierarchy used to represent local branches.
- Few special-purpose refs don't begin with `refs/` like `HEAD`.

- **per-worktree refs** are refs that are per-worktree, rather than being
  global. This is currently only HEAD and any other refs that start with
  `refs/bisect/`.

- reflog shows the local history of a ref. It can tell you things like what was
  the 3rd revision in this repository or the current state of this repository at
  XX:XX PM/AM on someday.

- **Symbolic Reference** or **symref** is a reference that contains a
  pointer to another reference. It has a format of `ref: refs/some/thing`
  and when its referenced, it recursively dereferences to that another
  reference. **HEAD** is a prime example of symref.

- **Special Refs** are refs that has different semantics than normal refs.
  These refs can be accessed via normal Git commands but may  not behave the
  same as a normal ref in some cases -
  1. **"FETCH_HEAD"** is written by `git fetch` or `git pull`. It may refer
     to multiple object IDs. Each object ID is annotated with metadata
     indicated where it was fetched from and its fetch status.
  2. **"MERGE_HEAD"** is written by `git merge` when resolving merge
     conflicts. It contains all commit IDs which are being merged.

- **pseudorefs** are a class of files under `$GIT_DIR` which behave like rfs
  for the purpose of rev-parse, but which are treated specially by git.
- Pseudorefs both have names  that are all-caps, & always  start with a line
  consisting of an SHA-1, followed by whitespace.
- HEAD is not a pseudoref, because it is sometimes a Symbolic ref.
- Pseudoref optionally might contain some additional data. For eg,
  `MERGE_HEAD` and `CHERRY_PICK_HEAD`.
- Unlike per-worktree refs, these files can't be symbolic refs, and never
  have reflogs. They also can't be updated through the normal ref update
  machinery.
- Instead, they are updated by directly writing to the files. However, they
  can be read as if they were  refs, so `git rev-parse MERGE_HEAD` will work.

## Dereferencing

- Unless otherwise specified, "dereferencing" as it used in the context of Git
  commands or protocols is always "implicitly recursive".
- **Referring to a symbolic reference -**
  The action of accessing the reference pointed at by a symbolic ref.
  Recursive dereferencing involves repeating the aforementioned process on
  the resulting ref until a non-symbolic reference is found.

- **Referring to a tag object -**
  the action of accessing the object a tag points at. Tags are recursively
  dereferenced by repeating the operation on the result object until the
  result has either a specified object type(where applicable) or any
  non-tag object type.

- **Referring to a commit object -**
  the action of accessing the commit's tree object. Commits cant be
  dereferenced recursively.

- A synonym for "recursive dereferencing" is called **peeling**.

## Repository

- **Repository** or **Git archive** is the collection of refs together with an
  Object
  Database
  containing all objects which are reachable from the refs, possibly accompanied
  by the metadata from one or more porcelains.
- **Bare repository** is directory with a .git suffix that does not have a locally
  checked-out copy of the files under revision control. All the Git
  administrative files and control files(generally present in .git directory)
  would be present in this `repository.git` and no other files are present or
  checked out.

- A **Shallow Repository** has an incomplete history. Some of the commits in
  such a repository have their parents cauterized away(Git is told to
  pretend that these commits don't have the parents, even though they are
  recorded in the commit object).
- Shallow Repositories are useful when you are interested only in the recent
  history of a project even though the real history recorded in the upstream
  might be much larger.
- A shallow repository is created by passing the --depth option to `git
  clone` and its history can later be deepened with `git fetch`.

- **origin** is the default upstream repository. Most projects have at least
  one upstream project which they track. By default, **origin** is used for
  that purpose.
- New upstream updates are fetched into remote-tracking branches named
  **origin/name-of-upstream-branch**, which can be accessed by `git branch -r`.

- **remote** is the repository which is used to track the same project but
  resides somewhere else. To communicate with remote, we use `fetch` and `push`.

- **submodule** is a repository that holds the history of a separate project
  inside another repository(latter is called super-project).
- **superproject** is a repository that references repositories of other
  projects in its working tree as submodules. The superproject knows about
  the names of (but does not hold copies of) commit objects of the contained
  submodules.

## Branches

- **branch** is a line of development.
- Most recent change(commit) to a branch is known as the tip of that branch.
- A single git repository can track multiple branches, but your working tree
  is associated with just one of them(the "current" or "checked out" branch)
  and HEAD points to that branch.

- **master** is the default development branch. Whenever you create a git
  repository, a branch named "master" is created, and it becomes the active
  branch.
- In most cases, master branch contains local development, though that is
  purely by convention.

- A **topic branch** is a regular git branch that is used by a developer to
  identify a conceptual line of development. Since branches are easy and
  inexpensive, it is often desirable to have several small branches that
  each contain very well-defined concepts or small incremental yet related
  changes.

- **Upstream Branch** is the default branch that is merged into the branch
  in question(or the branch in question is rebased onto).
- Upstream branches are configured via `branch.<name>.remote` and `branch.
  <name>.merge`.
- If the upstream branch of **A** is **origin/ B**, sometimes we say **A**
  is tracking **origin/ B**

- **remote-tracking branch** is a ref that is used to follow changes from
  another repository. It typically looks like
  `refs/remotes/remote-repo/some-branch`(indicating that it tracks a branch
  named `some-branch` in a remote named `remote-repo`), and matches the
  right-hand-side of a  configured fetch refspec.
- A **refspec** is used by `fetch` and `push` to describe the mapping
  between remote ref and local ref.

### Head

- **head** or **head ref** is a named reference to the commit at the tip of   any branch,
  which moved forward as more development is done on the branch. Heads are
  stored in `$GIT_DIR/refs/head`
- **HEAD** is the current branch. Your working tree is normally derived from the
  taste of the tree referred by HEAD. It's a reference to one of the heads in
  your repository, except when using a detached HEAD, which directly reference
  an arbitrary commit.

- Normally, HEAD stores the name of the branch, and commands that operate on the
  history - leading to the tip of the branch HEAD points at. However, Git allows
  you to check out an arbitrary commit that isn't necessarily the tip of any
  particular branch. HEAD in such a case is called **Detached HEAD**.
- If the head is detached, commands that operate on the history of the current
  branch still work. They update HEAD to a point at the tip of the updated
  history without affecting any branch. For eg, `git commit`
- If the head is detached, commands that operate on the current branch, try to
  update or inquire information about - will obviously not work since there is
  no current branch to ask about in this state. For
  example `git branch --set-upstream-to`

- The HEAD can point at a branch that does not exist yet, such a branch is
  called **Unborn Branch**.
- The typical way users encounter an unborn branch is by creating a
  repository anew without cloning from elsewhere. The HEAD would point at
  main(or master) branch that is yet to be born.
- **Orphan** is the act of getting on a branch that does not exist yet, i.e.
  an unborn branch. After such an operation, the commit first created
  becomes a commit without a parent, starting a new history.


### Index / Cache

- An **index** is a collection of files with stat information, whose contents
  are stored as objects. The index is a stored version of your working tree. It
  can contain the first, second, or even the third version of your working tree,
  which are used when merging.
- **index entry** is the information regarding a particular file, stored in the
  index. An index entry can be unmerged, if a merge was started but not yet
  finished( i.e. if the index contains multiple versions of that file ).

### Checking Out

- **checking out** means the action of updating all or part of a working tree
  with a tree object/ blob from the object database, & updating the index and
  HEAD if the whole working tree has been pointed to a new branch.

### Fetch

- **fetching** a branch means to get the branch's **head ref** from a
  remote repository, to find out what objects are missing from the local
  object database, and to get them, too.

### Merge and Pull

- **merging** means to bring the contents of another branch(possibly form an
  external repo) into the current branch.

- In the case where a merged-in branch is form a different repository,
  merging is done by - first fetching the remote branch and then merging the
  results on the current branch.
- This combination of "fetch" and "merge" is called **pull**.

- Merging is performed by an automatic process that identifies the changes
  made since the branch diverged, & then apply all those changes together.

- In cases where changes conflict, manual intervention may be required to
  complete the merge.

- A successful merge(unless its fast-forward) - results in the creation of a
  new commit representing the result of the merge, and having as parents the
  tips of merged branches.
- This commit is referred to as a "merge commit", or sometimes just a "merge".

- **octopus merge** means to merge more than two branches.
- An **evil merge** is a merge that introduces changes that do not appear in any
  parent.
- **fast-forward** is a special type of merge where you have a revision, and
  you're merging another branch's changed that happen to be a descendent of
  what you have.
- In such a case, you don't make a new merge commit but instead just update
  your branch to point at the same revision as the branch you're merging.
  This will happen frequently on a remote-tracking branch of a remote
  repository.

### Push

- **Pushing** a branch means:
  - to get the branch's "head ref" from a remote repository,
  - find out if it's an ancestor to the branch's local head ref, & in that case,
  - putting all objects, which are reachable from the local head ref, and
    which are missing from the remote repository - into the **remote object
    database**,
  - and updating the remote head ref.
- If the remote head is not an ancestor to the local head, the push fails.

### Rebase

- **Rebase** means to reapply a series of changes from a branch to a
  different base, and reset the head of that branch to the result.

### Resolve

- **Resolve** is the action of fixing up manually what a failed automatic
  merge left behind.

### Rewind

- **Rewind** means to throw away part of development i.e. to roll back to a
  past commit or assign the head to an earlier revision.

## Objects

- **Object** is the unit of storage in git. Uniquely identified by SHA-1 of its
  contents. An object can't be changed.
- Object Database stores a set of "objects" and an individual object is defined
  by its name. Located in `$GIT_DIR/objects`

- Via alternate mechanisms, if a repository is inheriting part of its object
  database from another object database, it's called an **alternate object
  database**.

- **Object Identifier**/ **Object Name** / **Hash** is the unique identifier to
  the object. Represented by a 40 character hexadecimal string. Also,
  colloquially called SHA-1.

- **Chain** is a list of objects, where each object in the list contains a
  reference to its successor.

- **pack** is a set of objects which have been compressed into one file (to
  save space or to transmit them efficiently).
- **pack index** is a list of identifiers, and other information, of the
  objects in a pack, to assist in efficiently accessing the contents a pack.

- Object types are - **tree**, **commit**, **tag**, and **blob**.

## Tree Object & Working Tree

- **Tree Object** is an object that contains the list of file names and modes
  along with refs to the associated blob and/or tree objects. Tree is equivalent
  to a directory.

- Working Tree is the tree of actual checkout files. It normally contains the
  content of the HEAD commit's tree, plus any local changes that you have made
  but not committed.

- One repository can have 0(in case of bare repositories), one or more worktrees
  attached to it. One **worktree** is consisted of a Working Tree and Repository
  Metadata, most of which is shared among other worktrees of a single
  repository, and others are separately maintained per worktree like index,
  HEAD, worktree refs, worktree configuration file, etc.

- A working tree is considered **clean** if it corresponds to the revision
  referenced by the current HEAD.
- A working tree is said to be **dirty** if it contains modifications that are
  yet not committed to the current branch.
- **Stash Entry** is an object used to temporarily store the contents of a
  dirty working directory and the index for future reuse.

- Git Repository can track multiple branches but Working Tree is associated only
  with current checked-out branch and HEAD(tip of the current branch), points to
  it.


## Commits

- **commit** is a single point in git history. Also called revision/ version or
  commit object.
- The entire history of a project is represented as a set of interrelated
  commits.
- committing means the action of storing a new snapshot of the project's state
  in the Git History, by creating a new commit object representing the current
  state of the index and advancing HEAD to point at the new commit.

- **Commit Object** contains the information about a particular revision,
  such as parents, committer, author, date, and the tree object which
  corresponds to the top directory of the stored revision.

- Commit Objects form a **Directed Acyclic Graph**(DAG), as they have parents (
  directed) and the graph of commit objects is acyclic(there is no chain which
  begins or ends with same object).

- **Commit Graph** is a synonym of DAG structure formed by commits in the object
  database, referenced by branch tips, using their chain of linked commits.
- A **commit-graph file** is supplemental representation of the commit graph
  which accelerates the commit graph walks. It's stored in `.git/objects/info` or
  in the info directory of an alternate object database.

- **commit-ish** is commit object can be recursively dereferenced to a commit
  object. Following are all commit-ishes - **a commit object**, **a tag
  object** that points to a commit object, a tag object that points to a tag
  object which points to a commit object, etc.

- **parent** is a commit object that contains a (possibly empty) list of
  logical predecessors in the line of development i.e. the parents.

- **Cherry Picking** means to extract a subset of changes out of a series of
  changes(typically commit) and to record them as a new series of changes on top
  of the current branch. In other words, it means choosing a commit from one
  branch and applying it to another.

- **pickaxe** refers to an option to the diffcore routines that help select
  changes that add or delete a given text string.
- With the `--pickaxe-all` option, it can be used to view the full changeset
  (commits) that introduced or removed, say, a particular line of text.

### Reachability

- All the ancestors of a given commit are said to be **reachable** from
  that commit.
- One object is reachable from another if we can reach the one from other by a
  chain. that -
  1. follows tags to whatever they tag,
  2. commits to their parents or trees
  3. trees to the trees or blobs that they contain
- Reachability Bitmaps store info about the reachability of a selected set
  of commits in a packfile, or a multi-pack index(MIDX) to speed up the
  object search.
- A repository can have at most a single `*.bitmap` file in use. It may
  belong to either one pack or the repo's MIDX, if it exists.

- **Unreachable Object** is an object that is not reachable from a branch,
  tag, or any other reference.

- **Dangling Object** is an unreachable object which is not reachable even
  from other unreachable objects. It has no reference to it from any
  reference or objects in the repository.

## Blob

- blob is an untyped object, for e.g. file content

## Tags

- A ref under `refs/tags/` namespace that points to an object of an
  arbitrary type(typically a tag points to either a tag or a commit object).
- In contrast to a head, a tag is not updated by the `commit` command.
- A Git tag has nothing to do with a Lisp tag(which would be called an
  object type in Git's context).
- A tag is most typically used to mark a particular point in the commit
  ancestry chain.
- **tag object** is an object containing the ref pointing to another object,
  which can contain a message just like a "commit object".
- Tag object can also contain a PGP Signature, in which case it's called a
  **signed tag object**.

## Hooks

- Call-outs are made to the optional script during the normal execution of
  several git commands which allows developers to add functionality or check.
- Hooks allow for a program to be pre-verified or potentially aborted.
- Hooks allow for a post-notification after the operation is done.
- Hook scripts can be found at `$GIT_DIR/hooks/` and they are enabled by
  simply removing the `.sample` suffix from the filename.
- In the older versions of git you had to change `.sample` suffix with `.exe`.

## Overlay

- Only update and add files to the working directory, but don't delete them,
  similar to how `cp -R` would update the contents in the destination
  directory.
- This is the default mode in a checkout when checking out files form the
  index or a tree-ish.
- In contrast, no-overlay mode also deletes tracked files not present in the
  source, similar to rsync --delete.

## Pathspec

- Pattern used to limit paths in Git commands.

- Pathspecs are used on the command line of `git ls-files`, `git ls-tree`,
  `git add`, `git grep`, `git diff`, `git checkout`, and many other commands
  to limit the scope of operations to some subset of the tree or working tree.
- Paths could be relative to the current directory or toplevel.
- The pathspec syntax is as follows -
  1. any path matches itself
  2. the pathspec up to the last slash represents a directory prefix. The
     scope of that pathspec is limited to that subtree.
  3. the rest of the pathspec is a pattern for the remainder of the
     pathname. Paths relative to the directory prefix will be matched
     against the pattern using fnmatch(3); in particular * and ? can match
     directory separators. 
- For example, `docs/*.jpg` will match all `*.jpg` files in the docs subtree, 
  including `docs/chap00/figure00.jpg`

- A pathspec that begins with a column `:` has a special meaning. 
- The leading colon `:` is followed by a zero or more "magic signature" 
  letters(which optionally is terminated by another colon `:`), and the 
  remainder is the pattern to match against the path. 
- The "magic signature" consists ASCII symbols that are neither alphanumeric,
  glob, regex special characters nor colon. 
- The optional colon that terminates the "magic signature" can be omitted if 
  the pattern begins with a character that does not belong to a "magic 
  signature" symbol set and is not a colon.

- In the long form, the leading colon `:` is followed by an open parenthesis 
  `(`, a comma-separated list of zero or more "magic words", and a close 
  parentheses `)`, and the remainder is the pattern tto match against the path.

- A pathspec with only a colon means "there is no pathspec". This form 
  should ot be combined with other pathspecs.

### top 

- The magic word `top`(magic signature: `/`) makes the pattern match from the 
root of the working tree, even when you are running the command from inside 
  a subdirectory. 

### literal 

- Wildcards in teh pattern such as `*` or `?` are treated as literal 
  characters. 

### icase

- case-insensitive match 

### glob

- Git treats the pattern as shell glob suitable for consumption by the 
  fnmatch(3) with the `FNM_PATHNAME` flag: wildcards in the pattern will not 
  match `a /` in the pathname. 
- For example, `docs/*.html`  matches `docs/git.html` but not `docs/ppc/ppc.
  html` or `tools/perf/docs/perf.html`.

- Two consecutive asterisks("`**`") in patterns matched against full 
  pathname may have special meaning: 
  1. A leading "`**`" followed by a slash means match in all directories. 
     For example, "`**/foo`" matches file or directory `foo` anywhere, the 
     same pattern as `foo`. "`**/foo/bar`" matches file or directory "`bar`" 
     anywhere that is directly under "`foo`".
  2. A trailing "`/**`" matches everything inside. For example, "`abc/**`" 
     matches all files inside directory "abc", relative to the location of 
     the `.gitignore` file with infinite depth. 
  3. A slash followed by two consecutive asterisks then a slash matches zero 
     or more directories. For example, "`a/**/b`" matches "`a/b`", "`a/x/b`",
     "`a/x/y/b`" and so on. 
  4. Other consecutive asterisks are considered invalid. Glob magic is 
     incompatible with literal magic. 

### attr 

- After `attr:` comes a space separated list of "attribute requirements", 
  all of which must be met in order for the path to be considered a match. 
  This is in addition to the usual non-magic pathspec pattern matching.

- Each of the attribute requirements for the path takes one of these forms:
  1. "`ATTR`" requires that the attribute `ATTR` be set. 
  2. "`-ATTR`" requires that the attribute `ATTR` be unset. 
  3. "`-ATTR=VALUE`" requires that the attribute `ATTR` be set to the string 
     `VALUE`.
  4. "`!ATTR`" requires that the attribute `ATTR` be unspecified.
- Note that, when matching  against a tree object, attributes are still 
  obtained from working tree, not from the given tree object.

### exclude

- After a path matches any non-exclude pathspec, it will be run through all 
  exclude pathspecs(magic signature: `!` or its synonym `^`). If it matches, 
  the path is ignored. 
- When there is no non-exclude pathspec, the exclusion is applied to the 
  result set as if invoked without any pathspec. 
