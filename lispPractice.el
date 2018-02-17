;; This buffer is for text that is not saved, and for Lisp evaluation.
;; To create a file, visit it with C-x C-f and enter text in its buffer.


(+ 1 1) ; 1+1
(+ 2 (* 3 4))

(setq my-name "yaxionh")
(message my-name)

(defun my-func ()
  (interactive)
  (message "hello, %s" my-name))

(my-func)

(global-set-key (kbd "<f1>") 'my-func)
